@Data
@NoArgsConstructor

public class Categoria{
    private int idCategoria;
    private String nombreCategoria;
    private String descripcionCategoria;

    public Categoria(){}

    public int getIdCategoria(){return this.idCategoria;}
    public String getNombreCategoria(){return this.nombreCategoria;}
    public String getDescripcionCategoria(){return this.descripcionCategoria;}

    public void setIdCategoria(int id){this.idCategoria=id;}
    public void setNombreCategoria(String nombre){this.nombreCategoria=nombre;}
    public void setDescripcionCategoria(String descripcion){this.descripcionCategoria=descripcion;}
}